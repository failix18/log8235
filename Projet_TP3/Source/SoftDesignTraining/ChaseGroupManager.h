#pragma once
#include "SDTAIController.h"
#include "CoreMinimal.h"

/**
 * 
 */
class SOFTDESIGNTRAINING_API ChaseGroupManager
{
public:   
    static ChaseGroupManager* GetInstance();
    static void Destroy();

    void AddAgentToGroup(ASDTAIController* agent);
    void RemoveAgentToGroup(ASDTAIController* agent);

    TArray<ASDTAIController*> m_chasingAgents;
    void debugDisplayMembers();

private:

    //SINGLETON
    ChaseGroupManager();
    static ChaseGroupManager* m_Instance;
};