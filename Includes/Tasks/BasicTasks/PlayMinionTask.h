#ifndef HEARTHSTONEPP_PLAY_MINION_TASK_H
#define HEARTHSTONEPP_PLAY_MINION_TASK_H

#include <Tasks/Requirement.h>
#include <Tasks/TaskAgent.h>
#include <Tasks/Tasks.h>

namespace Hearthstonepp::BasicTasks
{
//!
//! \brief PlayMinionTask class.
//!
//! This class represents the task for playing minion.
//! It summons minion and processes power.
//!
class PlayMinionTask : public ITask
{
 public:
    //! Constructs task with given \p agent and \p entity.
    //! \param agent The task agent that interacts with game interface.
    //! \param entity A pointer to minion to summon.
    PlayMinionTask(TaskAgent& agent, Entity* entity);

    //! Returns task ID.
    //! \return Task ID.
    TaskID GetTaskID() const override;

 private:
    //! Processes task logic internally and returns meta data.
    //! \param player1 The first player.
    //! \param player2 The second player.
    //! \return The result of task processing.
    MetaData Impl(Player& player1, Player& player2) override;

    Entity* m_entity;
    Requirement m_requirement;
};
}  // namespace Hearthstonepp::BasicTasks

#endif  // HEARTHSTONEPP_PLAYMINION_H
