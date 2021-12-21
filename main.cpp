#include <QPushButton>
#include <QApplication>
#include <QWidget>
#include <QProcess>
#include <QMessageBox>
#include <QFileDialog>
#include <QLabel>
#include <QDebug>
#include <QObject>
#include <QInputDialog>
#include <QFormLayout>
#include <QString>
#include <QCoreApplication>

void RunPythonScript()
{
    QProcess p;
    QStringList params;
    QString pythonPath = "C:/Users/admin/AppData/Local/Programs/Python/Python39/python.exe";
    QString pythonScript = "C:/Users/admin/PycharmProjects/lab_2/main.py";

    params << pythonScript;
    p.start(pythonPath, params);
    p.waitForFinished(-1);
    QString p_stdout = p.readAll();
    QString p_stderr = p.readAllStandardError();
    if (!p_stderr.isEmpty())
        qDebug() << "Python error:" << p_stderr;
    qDebug() << "Python result=" << p_stdout;
}

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QWidget* window = new QWidget;
    QLabel* label1 = new QLabel("Python Interpreter:", 0);
    QLineEdit* enter = new QLineEdit();
    QLabel* label2 = new QLabel("Input file:", 0);
    QLabel* lineEdit2 = new QLabel("C:/Users/admin/PycharmProjects/lab_2/87.txt", 0);
    QLabel* label3 = new QLabel("Output file:", 0);
    QLabel* lineEdit3 = new QLabel("C:/Users/admin/Desktop/lab4/output.txt", 0);
    QLabel* label4 = new QLabel("Running the script:", 0);
    QPushButton* button = new QPushButton("Start");

    QFormLayout* layout = new QFormLayout(window);
    layout->addRow(label1, enter);
    layout->addRow(label2, lineEdit2);
    layout->addRow(label3, lineEdit3);
    layout->addRow(label4, button);
    window->show();
    QObject::connect(button, &QPushButton::clicked, &app, &RunPythonScript);
    return QApplication::exec();
}
