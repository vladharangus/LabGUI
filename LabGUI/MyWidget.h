#pragma once
#include <QtWidgets/QApplication>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <vector>
#include "Service.h"
class MyWidget : public QWidget
{
private:
	void initGUI();
	void PopulateWithStatues();
	Service& service;
	QLineEdit* textBoxWordname;
	QLineEdit* textBoxAge;
	QLineEdit* textBoxMaterial;
	QLineEdit* textBoxCorporealForm;
	QHBoxLayout* hboxL;
	QPushButton *store;
	QPushButton *update;
	QPushButton *add;
	QPushButton *Delete;
	QWidget* actions;
	QWidget* details;
	QListWidget* statueList;

public:
	MyWidget(Service& service, QWidget * parent = Q_NULLPTR);
	~MyWidget();
};

