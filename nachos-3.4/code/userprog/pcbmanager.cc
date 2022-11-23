#include "pcbmanager.h"


PCBManager::PCBManager(int maxProcesses) {

    bitmap = new BitMap(maxProcesses);
    pcbs = new PCB*[maxProcesses];

    for(int i = 0; i < maxProcesses; i++) {
        pcbs[i] = NULL;
    }

}


PCBManager::~PCBManager() {

    delete bitmap;

    delete pcbs;

}


PCB* PCBManager::AllocatePCB() {

    // Aquire pcbManagerLock

    int pid = bitmap->Find();

    // Release pcbManagerLock

    ASSERT(pid != -1);

    pcbs[pid] = new PCB(pid);

    return pcbs[pid];

}


int PCBManager::DeallocatePCB(PCB* pcb) {

    // Check is pcb is valid -- check pcbs for pcb->pid

     // Aquire pcbManagerLock

    bitmap->Clear(pcb->pid);

    // Release pcbManagerLock

    int pid = pcb->pid;

    delete pcbs[pid];

    pcbs[pid] = NULL;

}

PCB* PCBManager::GetPCB(int pid) {
    return pcbs[pid];
}