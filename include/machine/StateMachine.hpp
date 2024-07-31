#pragma once

#include "machine/State.hpp"
#include <memory>
#include <stack>


namespace GameOfLife{
    typedef std::unique_ptr<State> StateRef;

    class StateMachine{
        public:
            StateMachine(){}
            ~StateMachine(){}

            void AddState(StateRef state, bool isReplacing=true);
            void RemoveState();
            void ProcessStateChanges();
            StateRef &GetActiveState();

        private:
            std::stack<StateRef> states;
            StateRef state;
            bool isRemoving, isAdding, isReplacing;
    };
}
