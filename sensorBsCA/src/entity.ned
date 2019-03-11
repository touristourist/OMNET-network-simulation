

package sensorBs;

//
// This module represent a simple entity in the network
//
simple Entity     //实体是所有元件的父类
{
    parameters:
        @class(Entity);
        int x = default(0); // Position X
        int y = default(0); // Position Y
}
