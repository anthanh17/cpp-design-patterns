/*
 * C++ Design Patterns: Abstract Factory
 * Author: AnNT
 * 2023
 */

#include <iostream>
#include <memory>

// ----------------------------- BUTTON ----------------------------------------
class Button {
 public:
  Button() = default;
  Button(const Button&) = delete;
  Button& operator=(const Button&) = delete;
  virtual ~Button() = default;
};

class LightButton final : public Button {
 public:
  LightButton() { std::cout << "\nThis is Light Button!"; }
  LightButton(const LightButton&) = delete;
  LightButton& operator=(const LightButton&) = delete;
  ~LightButton() = default;
};

class DarkButton final : public Button {
 public:
  DarkButton() { std::cout << "\nThis is Dark Button!"; }
  DarkButton(const DarkButton&) = delete;
  DarkButton& operator=(const DarkButton&) = delete;
  ~DarkButton() = default;
};
// -----------------------------------------------------------------------------
// ---------------------------- SCROLLBAR --------------------------------------
class ScrollBar {
 public:
  ScrollBar() = default;
  ScrollBar(const ScrollBar&) = delete;
  ScrollBar& operator=(const ScrollBar&) = delete;
  virtual ~ScrollBar() = default;
};

class LightScrollBar final : public ScrollBar {
 public:
  LightScrollBar() { std::cout << "\nThis is Light ScrollBar!"; }
  LightScrollBar(const LightScrollBar&) = delete;
  LightScrollBar& operator=(const LightScrollBar&) = delete;
  ~LightScrollBar() = default;
};

class DarkScrollBar final : public ScrollBar {
 public:
  DarkScrollBar() { std::cout << "\nThis is Dark ScrollBar!"; }
  DarkScrollBar(const DarkScrollBar&) = delete;
  DarkScrollBar& operator=(const DarkScrollBar&) = delete;
  ~DarkScrollBar() = default;
};
// -----------------------------------------------------------------------------
// ------------------------------- WIDGET --------------------------------------
class WidgetAbstractFactory {
 public:
  WidgetAbstractFactory() = default;
  WidgetAbstractFactory(const WidgetAbstractFactory&) = delete;
  WidgetAbstractFactory& operator=(const WidgetAbstractFactory&) = delete;
  ~WidgetAbstractFactory() = default;

  virtual std::unique_ptr<Button> CreateButton() = 0;
  virtual std::unique_ptr<ScrollBar> CreateScrollBar() = 0;
};

class LightTheme final : public WidgetAbstractFactory {
 public:
  LightTheme() = default;
  LightTheme(const LightTheme&) = delete;
  LightTheme& operator=(const LightTheme&) = delete;
  ~LightTheme() = default;

  std::unique_ptr<Button> CreateButton() override {
    return std::make_unique<LightButton>();
  }

  std::unique_ptr<ScrollBar> CreateScrollBar() override {
    return std::make_unique<LightScrollBar>();
  }
};

class DarkTheme final : public WidgetAbstractFactory {
 public:
  DarkTheme() = default;
  DarkTheme(const DarkTheme&) = delete;
  DarkTheme& operator=(const DarkTheme&) = delete;
  ~DarkTheme() = default;

  std::unique_ptr<Button> CreateButton() override {
    return std::make_unique<DarkButton>();
  }

  std::unique_ptr<ScrollBar> CreateScrollBar() override {
    return std::make_unique<DarkScrollBar>();
  }
};
// -----------------------------------------------------------------------------
int main() {
  const auto factory_light_theme = std::make_unique<LightTheme>();
  const auto factory_dark_theme = std::make_unique<DarkTheme>();

  const auto button_light = factory_light_theme->CreateButton();
  const auto scroll_bar_light = factory_light_theme->CreateScrollBar();

  const auto button_dark = factory_dark_theme->CreateButton();
  const auto scroll_bar_dark = factory_dark_theme->CreateScrollBar();
  return 0;
}
