// Fill out your copyright notice in the Description page of Project Settings.

#include "ChaseGroupManager.h"
#include "SoftDesignTraining.h"
#include "EngineGlobals.h"

ChaseGroupManager* ChaseGroupManager::m_Instance;

ChaseGroupManager::ChaseGroupManager()
{
}

ChaseGroupManager* ChaseGroupManager::GetInstance()
{
    if (!m_Instance)
    {
        m_Instance = new ChaseGroupManager();
    }

    return m_Instance;
}

void ChaseGroupManager::Destroy()
{
    delete m_Instance;
    m_Instance = nullptr;
}

void ChaseGroupManager::AddAgentToGroup(ASDTAIController* agent)
{
    m_chasingAgents.Add(agent);
}

void ChaseGroupManager::RemoveAgentToGroup(ASDTAIController* agent)
{
    m_chasingAgents.Remove(agent);
}

void ChaseGroupManager::debugDisplayMembers()
{
    FString debugString = "Chase group: Nobody";
    if (m_chasingAgents.Num() > 0)
    {
        debugString = "Chase group: " + m_chasingAgents[0]->GetName();
        for (int i = 0; i < m_chasingAgents.Num(); i++)
        {
            debugString += ", " + m_chasingAgents[i]->GetName();
        }

    }
    GEngine->AddOnScreenDebugMessage(666, 666, FColor::Red, debugString);
}