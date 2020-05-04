#include "LabGUI.h"
#include <QtWidgets/QApplication>
#include "MyWidget.h"
#include "FileRepository.h"
#include "CVS_HTMLRepository.h"
#include "Statue.h"
#include "Service.h"
#include <vector>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	std::vector<Statue> listmodeA;
	std::vector<Statue> listmodeB;
	FileRepository repomodeA{ "repoModeA.txt",listmodeA };
	CSV_HTMLRepository repomodeB{ listmodeB };
	Service service{repomodeA, repomodeB};
	MyWidget mw{ service };
	mw.show();
	
	return a.exec();
}
