#ifndef TEST1_ANALYZER_RESULTS
#define TEST1_ANALYZER_RESULTS

#include <AnalyzerResults.h>

class Test1Analyzer;
class Test1AnalyzerSettings;

class Test1AnalyzerResults : public AnalyzerResults
{
public:
	Test1AnalyzerResults( Test1Analyzer* analyzer, Test1AnalyzerSettings* settings );
	virtual ~Test1AnalyzerResults();

	virtual void GenerateBubbleText( U64 frame_index, Channel& channel, DisplayBase display_base );
	virtual void GenerateExportFile( const char* file, DisplayBase display_base, U32 export_type_user_id );

	virtual void GenerateFrameTabularText(U64 frame_index, DisplayBase display_base );
	virtual void GeneratePacketTabularText( U64 packet_id, DisplayBase display_base );
	virtual void GenerateTransactionTabularText( U64 transaction_id, DisplayBase display_base );

protected: //functions

protected:  //vars
	Test1AnalyzerSettings* mSettings;
	Test1Analyzer* mAnalyzer;
};

#endif //TEST1_ANALYZER_RESULTS
