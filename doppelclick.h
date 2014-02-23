#ifndef DOPPELCLICK_H
#define DOPPELCLICK_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QSlider>

#define TIME_HARD 200
#define TIME_NORMAL 400
#define TIME_EASY 600
#define GOOD "<img src='images/good.jpg'>"
#define BAD "<img src='images/bad.jpg'>"
#define NEUTRAL "<img src='images/neutral.jpg'>"

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
        qint64 timeDifficult;

	private slots:
        void buttonClicked(void);
        void setDifficulty(int value);
	
	signals:
		void gameFinished();
};

#endif // DOPPELCLICK_H
