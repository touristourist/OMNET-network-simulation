


#ifndef __MULTITARGETTRACKING_ENTITY_H_
#define __MULTITARGETTRACKING_ENTITY_H_

#include <omnetpp.h>

#define BS 1   //type
#define CA1 2
#define CA2 3
#define CA3 4

/**
 * This class represents an entity in the network. All entities should be subclass of this class.
 */
class Entity : public cSimpleModule
{
    protected:
        int x, y; // Position

        virtual void initialize();
        virtual void handleMessage(cMessage *msg);

    public:
        int getX();
        void setX(int x);
        int getY();
        void setY(int y);
        // Update display of entity, default behavior is empty
        virtual void updateDisplay();   //更新在图上的展示
        // Get distance from current entity to the other
        double distance(Entity *obj);   //和另一个entity的距离
};

#endif
