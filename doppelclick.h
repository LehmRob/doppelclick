#ifndef DOPPELCLICK_H
#define DOPPELCLICK_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QSlider>

namespace Ui {
        class Doppelclick;
}

class Doppelclick : public QWidget
{
	Q_OBJECT

	public:
		explicit Doppelclick(QWidget *parent=0);

	private:
		/* private Methodes */
		void initializeUi(void);

		/* GUI Elements */
		QPushButton *doppelButton;
		QLabel *gameStateLabel;
		QLabel *gameIcon;
		QSlider *diffiSlider;
		
		/* Global Variables */
		bool gameRunning;
		qint64 startTime;
		QString bad;
		QString god;
        QString neutral;
        qint64 diffiVal;



	private slots:
        void buttonClicked(void);
        void changeDifficulty(void);
};

#endif // DOPPELCLICK_H
