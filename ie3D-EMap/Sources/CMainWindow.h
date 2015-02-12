#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include "HCommon.h"
#include "HMEDeclaration.h"
#include "HEnums.h"
#include "IConfiguration.h"
#include "IRenderTechniqueOperationTextureHandler.h"

class CMEGameController;
class CMEmseTransition;
class CMEgopTransition;
class CMEgoeTransition;

namespace Ui {
    class CMainWindow;
}

class CMainWindow :
public QMainWindow,
public std::enable_shared_from_this<CMainWindow>
{
    Q_OBJECT
    
protected:
    
#if defined(__OSX__) || defined(__WIN32__)
    
    std::shared_ptr<CMEGameController> m_mseController;
    std::shared_ptr<CMEmseTransition> m_mseTransition;
    
    std::shared_ptr<CMEGameController> m_gopController;
    std::shared_ptr<CMEgopTransition> m_gopTransition;
    
    std::shared_ptr<CMEGameController> m_goeController;
    std::shared_ptr<CMEgoeTransition> m_goeTransition;
    
    ISharedUICommands m_mseSceneToUICommands;
    ISharedUICommands m_goeSceneToUICommands;
    
    void setMSEBrushSize(ui32 value);
    void setMSEBrushStrength(ui32 value);
    void setMSEFalloffCoefficient(ui32 value);
    void setMSESmoothCoefficient(ui32 value);
    void setMSETexture(CSharedTextureRef texture, E_SHADER_SAMPLER sampler);
    void setMSETillingTexcoord(f32 value, E_SHADER_SAMPLER sampler);
    
    void updateGOEConfigurationsMaterials(std::vector<CSharedConfigurationMaterial>& configurations);
    
    i32 m_brushSize;
    std::string m_recentOpenPath;
    
    bool event(QEvent *event);
    
#endif
    
public:
    
    explicit CMainWindow(QWidget *parent = 0);
    ~CMainWindow();
    
    void execute(void);
    
private slots:
    void on_m_brushSizeSlider_valueChanged(int value);

    void on_m_brushStrengthSlider_valueChanged(int value);

    void on_m_falloffSlider_valueChanged(int value);

    void on_m_smoothSlider_valueChanged(int value);

    void on_m_texture01Btn_pressed();

    void on_m_texture01Btn_clicked();

    void on_m_texture02Btn_clicked();

    void on_m_texture03Btn_clicked();

    void on_m_textureTilling01SpinBox_valueChanged(int arg1);

    void on_m_textureTilling02SpinBox_valueChanged(int arg1);

    void on_m_textureTilling03SpinBox_valueChanged(int arg1);

    void on_generateButton_clicked();

    void on_m_mainMenuTabs_currentChanged(int index);

    void on_m_landscapePropertiesTab_currentChanged(int index);

    void on_m_createGameObjectConfiguration_clicked();

private:
    
    Ui::CMainWindow *ui;
};

#endif
