#ifndef CSVPREFERENCES_H
#define CSVPREFERENCES_H

#include <QWidget>
#include "ui_csvPreferences.h"

class csvPreferences : public QWidget
{
	Q_OBJECT

public:
	csvPreferences(QWidget *parent = 0);
	~csvPreferences();

	Ui::csvPreferences ui;

private:
};

#endif // CSVPREFERENCES_H
