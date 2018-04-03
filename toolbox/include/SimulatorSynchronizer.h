#ifndef WBT_SIMULATORSYNCHRONIZER_H
#define WBT_SIMULATORSYNCHRONIZER_H

#include "Block.h"
#include <memory>

namespace wbt {
    class SimulatorSynchronizer;
}

class wbt::SimulatorSynchronizer : public wbt::Block
{
public:
    static const std::string ClassName;

    SimulatorSynchronizer();
    ~SimulatorSynchronizer() override = default;

    unsigned numberOfParameters() override;
    std::vector<std::string> additionalBlockOptions() override;
    bool configureSizeAndPorts(BlockInformation* blockInfo) override;
    bool initialize(const BlockInformation* blockInfo) override;
    bool terminate(const BlockInformation* blockInfo) override;
    bool output(const BlockInformation* blockInfo) override;

private:
    double m_period;
    bool m_firstRun;

    struct RPCData;
    std::unique_ptr<RPCData> m_rpcData;
};

#endif /* end of include guard: WBT_SIMULATORSYNCHRONIZER_H */
