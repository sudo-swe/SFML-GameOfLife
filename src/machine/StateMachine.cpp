#include "machine/StateMachine.hpp"

#include <utility>

namespace GameOfLife {
    void StateMachine::AddState(StateRef state, bool isReplacing){
        this->isAdding = true;
        this->isReplacing = isReplacing;
        this->state = std::move(state);
    }

    void StateMachine::RemoveState(){
        this->isRemoving = true;
    }

    void StateMachine::ProcessStateChanges(){
        if(this->isRemoving && !this->states.empty()){
            this->states.pop();
            this->isRemoving = false;
        }

        if(this->isAdding){
            if(!this->states.empty()){
                if(this->isReplacing) this->states.pop();
            }
            this->states.push(std::move(this->state));
            this->states.top()->Init();
            this->isAdding = false;
        }
    }

    StateRef &StateMachine::GetActiveState(){
        return this->states.top();
    }
}
