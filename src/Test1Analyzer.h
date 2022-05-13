#ifndef TEST1_ANALYZER_H
#define TEST1_ANALYZER_H

#include <Analyzer.h>
#include "Test1AnalyzerResults.h"
#include "Test1SimulationDataGenerator.h"

class Test1AnalyzerSettings;
class ANALYZER_EXPORT Test1Analyzer : public Analyzer2
{
public:
	Test1Analyzer();
	virtual ~Test1Analyzer();

	virtual void SetupResults();
	virtual void WorkerThread();

	virtual U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channels );
	virtual U32 GetMinimumSampleRateHz();

	virtual const char* GetAnalyzerName() const;
	virtual bool NeedsRerun();

protected: //vars
	std::auto_ptr< Test1AnalyzerSettings > mSettings;
	std::auto_ptr< Test1AnalyzerResults > mResults;
	AnalyzerChannelData* mSerial;

	Test1SimulationDataGenerator mSimulationDataGenerator;
	bool mSimulationInitilized;

	//Serial analysis vars:
	U32 mSampleRateHz;
	U32 mStartOfStopBitOffset;
	U32 mEndOfStopBitOffset;
};

extern "C" ANALYZER_EXPORT const char* __cdecl GetAnalyzerName();
extern "C" ANALYZER_EXPORT Analyzer* __cdecl CreateAnalyzer( );
extern "C" ANALYZER_EXPORT void __cdecl DestroyAnalyzer( Analyzer* analyzer );

#endif //TEST1_ANALYZER_H
