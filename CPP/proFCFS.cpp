
#include "../Headers/proFCFS.h"
#include "../Headers/schedular.h"


ProFCFS::ProFCFS(Schedular* p) :processor(p)
{
	timer = 0;

	RUNLIST = nullptr;
}

ProFCFS::~ProFCFS()
{}

int ProFCFS::gettimer() const
{
	return timer;

}

bool ProFCFS::ScheduleAlgo()
{
	if (RUNLIST = nullptr) {

		  Plist.getbeg(RUNLIST);

	}else
		if (RUNLIST->getremainingtime() != 0) {
			return;
		}
		else 
			if (RUNLIST->getremainingtime() == 0) {

				//pS->//move to TRM;
				RUNLIST = nullptr;


			}




}

void ProFCFS::forkingrequest(int AT, int RT)
{}

void ProFCFS::inctimer(Process* p)
{
	timer += p->getremainingtime();
}

void ProFCFS::dectimer(Process* p)
{
	timer -= p->getremainingtime();
}

void ProFCFS::add_process(Process* p)
{
	Plist.InsertEnd(p);


}

