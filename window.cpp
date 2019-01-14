#include "window.hpp"

#include "maze.hpp"

#include <QPainter>
#include <QPaintEvent>
#include <QPen>

window::window(QWidget* p)
	:QWidget(p)
{
	m_maze = new maze_generator();
	m_maze->generate(20, 20);
}

void window::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(QPen(Qt::black, 2));
	int r = 20, c = 20;
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			const cell& cell = m_maze->get_cell(i, j);
			if (cell.top_wall()) {
				painter.drawLine(r, c, r + 20, c);
			}
			if (cell.left_wall()) {
				painter.drawLine(r, c, r, c + 20);
			}
			if (j == 19 && cell.right_wall()) {
				painter.drawLine(r + 20, c, r + 20, c + 20);
			}
			if (i == 19) {
				painter.drawLine(r, c + 20, r + 20, c + 20);
			}
			r += 20;
		}
		r = 20;
		c += 20;
	}
}