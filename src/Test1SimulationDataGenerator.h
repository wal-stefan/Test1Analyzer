#ifndef TEST1_SIMULATION_DATA_GENERATOR
#define TEST1_SIMULATION_DATA_GENERATOR

#include <SimulationChannelDescriptor.h>
#include <string>
class Test1AnalyzerSettings;

class Test1SimulationDataGenerator
{
public:
	Test1SimulationDataGenerator();
	~Test1SimulationDataGenerator();

	void Initialize( U32 simulation_sample_rate, Test1AnalyzerSettings* settings );
	U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channel );

protected:
	Test1AnalyzerSettings* mSettings;
	U32 mSimulationSampleRateHz;

protected:
	void CreateSerialByte();
	std::string mSerialText;
	U32 mStringIndex;

	SimulationChannelDescriptor mSerialSimulationData;

};
#endif //TEST1_SIMULATION_DATA_GENERATOR