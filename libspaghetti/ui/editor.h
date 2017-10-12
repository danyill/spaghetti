// MIT License
//
// Copyright (c) 2017 Artur Wyszyński, aljen at hitomi dot pl
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once
#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <QMap>

#include "core/api.h"

namespace Ui {
class Editor;
}

class QGraphicsItem;
class PackageView;

class SPAGHETTI_API Editor final : public QMainWindow {
  Q_OBJECT

 public:
  explicit Editor(QWidget *a_parent = nullptr);
  ~Editor();

  void newPackage();
  void tabCloseRequested(int a_index);
  void tabChanged(int a_index);

  void populateElementsList();
  void addElement(QString a_category, QString a_name, QString a_type, QString a_icon);

  void aboutToQuit();

  PackageView *currentPackageView() const { return m_currentPackageView; }

 protected:
  void showEvent(QShowEvent *a_event);

 private:
  Ui::Editor *m_ui{};
  PackageView *m_currentPackageView{};
};

#endif // EDITOR_H
