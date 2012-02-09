/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

#ifndef __qMRMLReportingAnnotationRANOWidget_h
#define __qMRMLReportingAnnotationRANOWidget_h

// Qt includes
#include <QWidget>

// CTK includes
#include <ctkPimpl.h>
#include "ctkVTKObject.h"

// qMRML includes
#include "qMRMLWidget.h"
#include "qSlicerReportingModuleWidgetsExport.h"

// MRML includes

class qMRMLReportingAnnotationRANOWidgetPrivate;
class vtkMRMLNode;
class vtkMRMLReportingAnnotationNode;
class vtkMRMLScene;

class Q_SLICER_MODULE_REPORTING_WIDGETS_EXPORT qMRMLReportingAnnotationRANOWidget : public qMRMLWidget
{
  Q_OBJECT
  QVTK_OBJECT
  Q_PROPERTY(int measurableDiseaseIndex READ measurableDiseaseIndex WRITE setMeasurableDiseaseIndex)
  Q_PROPERTY(int nonmeasurableDiseaseIndex READ nonmeasurableDiseaseIndex WRITE setNonmeasurableDiseaseIndex)
  Q_PROPERTY(int flairIndex READ flairIndex WRITE setFlairIndex)

public:
  /// Superclass typedef
  typedef qMRMLWidget Superclass;

  /// Constructors
  explicit qMRMLReportingAnnotationRANOWidget(QWidget* parent=0);
  virtual ~qMRMLReportingAnnotationRANOWidget();

  /// Utility function that returns the mrml scene of the layout manager
  vtkMRMLScene* mrmlScene()const;

  int measurableDiseaseIndex() const;
  void setMeasurableDiseaseIndex(int);
  int nonmeasurableDiseaseIndex() const;
  void setNonmeasurableDiseaseIndex(int);
  int flairIndex() const;
  void setFlairIndex(int);

public slots:
  /// Set the MRML node
  void setMRMLAnnotationNode(vtkMRMLNode* node);
  void updateWidgetFromMRML();

private slots:
  void onMeasurableDiseaseChanged(int);
  void onNonmeasurableDiseaseChanged(int);
  void onFlairChanged(int);

protected:
  QScopedPointer<qMRMLReportingAnnotationRANOWidgetPrivate> d_ptr;

  void init();

private:
  Q_DECLARE_PRIVATE(qMRMLReportingAnnotationRANOWidget);
  Q_DISABLE_COPY(qMRMLReportingAnnotationRANOWidget);
};

#endif
