#include "imageanalyzer.h"

ImageAnalyzer::ImageAnalyzer()
{
}

void ImageAnalyzer::start(QString filePath)
{
    this->ColorCount.clear();
    if (image.load(filePath)) {
        this->height = image.height();
        this->width = image.width();
        QVector<QString> colors;
        for (int x=0; x < this->height; x++) {
            for (int y=0; y < this->width; y++) {
                QString value = ((QColor)image.pixel(y, x)).name();
                if(!colors.contains(value))
                    colors.push_back(value);
            }
        }
        this->colors = colors;
    }
}

int ImageAnalyzer::getHeight() const
{
    return this->height;
}

int ImageAnalyzer::getWidth() const
{
    return this->width;
}

QVector<QString> ImageAnalyzer::getColorCount()
{
    return this->colors;
}
