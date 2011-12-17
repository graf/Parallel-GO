#include "graph.h"

DefineGraph::DefineGraph(int NambPred, int NambTop)
{
    this->NambPred = NambPred;
    this->NambTop = NambTop;
}

DefineTop::DefineTop(const char *NameTop, int FirstDef, int LastDef, int (*top)(TPOData *))
{
    this->NameTop = NameTop;
    this->FirstDef = FirstDef;
    this->LastDef = LastDef;
    this->top = top;
}

DefinePredicate::DefinePredicate(const char *name, int (*predicate)(TPOData *))
{
    this->name = name;
    this->predicate = predicate;
}
