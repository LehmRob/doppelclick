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
        qint64 timeDifficult;



	private slots:
        void buttonClicked(void);
        void setDifficulty(int value);
};

#endif // DOPPELCLICK_H
