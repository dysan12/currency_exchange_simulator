#ifndef MODELCONNECTION_H
#define MODELCONNECTION_H

#include "model.h"
#include "serverconnection.h"

class ModelConnection : public Model
{
public:
    ServerConnection *servcon;
    ModelConnection();
};

#endif // MODELCONNECTION_H
