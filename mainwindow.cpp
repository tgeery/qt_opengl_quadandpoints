#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
{
    setSurfaceType(QWindow::OpenGLSurface);
    setTitle("OpenGL Example");
    resize(QSize(640,480));

    QSurfaceFormat fmt;
    fmt.setProfile(QSurfaceFormat::CompatibilityProfile);
    fmt.setVersion(2,1);

    ctx = new QOpenGLContext;
    ctx->setFormat(fmt);
    ctx->create();
    ctx->makeCurrent(this);

    functions = ctx->functions();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initializeGL()
{}

void MainWindow::resizeGL(int w, int h)
{}

void MainWindow::paintGL()
{
    glClearColor(0.0, 0.25, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);

    glEnd();

//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    glPointSize(10.0f);

    glBegin(GL_POINTS);

    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);

    glEnd();

    glFlush();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{}

void MainWindow::paintEvent(QPaintEvent *event)
{
    paintGL();
}
