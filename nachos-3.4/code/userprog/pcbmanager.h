#ifndef PCBMANAGER_H
#define PCBMANAGER_H

#include "bitmap.h"
#include "pcb.h"

class PCB;

class PCBManager {

    public:
        PCBManager(int maxProcesses);
        ~PCBManager();

        PCB* AllocatePCB();
        int DeallocatePCB(PCB* pcb);
        PCB* GetPCB(int pid);

    private:
        BitMap* bitmap;
        PCB** pcbs;
        // Need a lock here
        // Lock* pcbManagerLock;

};

#endif // PCBMANAGER_H