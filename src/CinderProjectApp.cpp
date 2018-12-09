#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

class CinderProjectApp : public App {
public:
  void setup() override;
  void update() override;
  void draw() override;
  void conditionalReset();
  float getMaxRadius() const;

private:
  float       _radius{};
  float       _lineWidth{};
  const Color _bgColor{ Color{0, 0, 0} };
  const Color _penColor{ Color{1, 1, 1} };
};

void CinderProjectApp::setup()
{
  _radius = (std::min(getWindowWidth(), getWindowHeight()) / 4.0f);
  _lineWidth = 1.0f;
  gl::color(_bgColor);
  gl::drawSolidRect(Rectf(getWindowBounds()));
  gl::color(_penColor);
}

float CinderProjectApp::getMaxRadius() const
{
  return std::min(getWindowWidth(), getWindowHeight()) / 2.0f;
}

void CinderProjectApp::conditionalReset()
{
  if (_radius > getMaxRadius())
  {
    setup();
  }
}

void CinderProjectApp::update()
{
  conditionalReset();
  _radius += 1;
}

void CinderProjectApp::draw()
{
  gl::drawStrokedCircle(getWindowCenter(), _radius);
}

CINDER_APP(CinderProjectApp, RendererGl)