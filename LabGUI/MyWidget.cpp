#include "MyWidget.h"



void MyWidget::initGUI()
{

	QHBoxLayout* vL = new QHBoxLayout{ this };

	QVBoxLayout* functionalities = new QVBoxLayout{};
	QVBoxLayout* list = new QVBoxLayout{};
	//create an information widget, with a QFormLayout
	this->details = new QWidget{};
	QFormLayout *fL = new QFormLayout{};
	this->details->setLayout(fL);
	QLabel *labelWordname = new QLabel{ "&Wordname" };
	this->textBoxWordname = new QLineEdit{};
	labelWordname->setBuddy(this->textBoxWordname);
	fL->addRow(labelWordname, this->textBoxWordname);

	QLabel *labelMaterial = new QLabel{ "&Material" };
	this->textBoxMaterial = new QLineEdit{};
	labelMaterial->setBuddy(this->textBoxMaterial);
	fL->addRow(labelMaterial, this->textBoxMaterial);

	QLabel *labelAge = new QLabel{ "&Age" };
	this->textBoxAge = new QLineEdit{};
	labelAge->setBuddy(this->textBoxAge);
	fL->addRow(labelAge, this->textBoxAge);

	QLabel *labelCorporealForm = new QLabel{ "&CorporealForm" };
	this->textBoxCorporealForm = new QLineEdit{};
	labelCorporealForm->setBuddy(this->textBoxCorporealForm);
	fL->addRow(labelCorporealForm, this->textBoxCorporealForm);

	//add the information widget to the window
	functionalities->addWidget(details);

	this->actions = new QWidget{};
	QHBoxLayout* hboxL = new QHBoxLayout{};
	this->store = new QPushButton{ "&Save" };
	this->update = new QPushButton{ "&Update" };
	this->add = new QPushButton{ "&Add" };
	this->Delete = new QPushButton{ "&Delete" };
	hboxL->addWidget(this->store);
	hboxL->addWidget(this->update);
	hboxL->addWidget(this->add);
	hboxL->addWidget(this->Delete);
	this->actions->setLayout(hboxL);

	// add the actions widget to the window
	functionalities->addWidget(this->actions);

	this->PopulateWithStatues();
	list->addWidget(this->statueList);
	vL->addLayout(functionalities);
	vL->addLayout(list);

}

void MyWidget::PopulateWithStatues()
{
	this->statueList = new QListWidget{};
	std::vector<Statue> listofstatues = this->service.GetStatues();
	for (auto &s : listofstatues)
	{
		this->statueList->addItem(QString::fromStdString(
			s.GetWordName() + ", " + s.GetMaterial() + ", " + std::to_string(s.GetAge()) + ", " + s.GetCorporealForm()));
	}
}

MyWidget::MyWidget(Service& service, QWidget* parent) : QWidget{ parent }, service{service}
{
	this->initGUI();
}


MyWidget::~MyWidget()
{
}
