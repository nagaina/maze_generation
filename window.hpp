#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QWidget>

class QPaintEvent;
class maze_generator_interface;

class window : public QWidget
{
public:
	window(QWidget* p = 0);

	~window() {}
	
protected:
	virtual void paintEvent(QPaintEvent* event) override;

private:
	maze_generator_interface* m_maze;
};
#endif
