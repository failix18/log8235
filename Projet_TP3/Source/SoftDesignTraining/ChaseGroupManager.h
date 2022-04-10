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
    void RemoveAgentFromGroup(ASDTAIController* agent);

    void debugDisplayMembers();

private:

    //SINGLETON
    ChaseGroupManager();
    static ChaseGroupManager* m_Instance;

    // Array of current members of the chase group
    TArray<ASDTAIController*> m_chasingAgents;
};