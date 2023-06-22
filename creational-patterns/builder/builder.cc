/*
 * C++ Design Patterns: Observer
 * Author: AnNT
 * 2023
 */

#include <iostream>
#include <memory>
#include <string_view>

// Create class store information products
class ElectronicProduct final {
 public:
  ElectronicProduct() = default;
  ElectronicProduct(const ElectronicProduct&) = delete;
  ElectronicProduct& operator=(const ElectronicProduct&) = delete;
  ~ElectronicProduct() = default;

  void SetPhone(std::string_view phone) { phone_ = phone; }

  void SetTablet(std::string_view tablet) { tablet_ = tablet; }

  void SetScreen(std::string_view screen) { screen_ = screen; }

  void SetLaptop(std::string_view laptop) { laptop_ = laptop; }

  void ShowInfor(void) {
    std::cout << "\nPhone: " << phone_;
    std::cout << "\nTablet: " << tablet_;
    std::cout << "\nScreen: " << screen_;
    std::cout << "\nLaptop: " << laptop_;
  }

 private:
  std::string_view phone_;
  std::string_view tablet_;
  std::string_view screen_;
  std::string_view laptop_;
};

// -------------------------- INTERFACE BUILDER --------------------------------

class IShopBuilder {
 public:
  virtual ~IShopBuilder() = default;

  virtual std::unique_ptr<ElectronicProduct> GetProduct() = 0;

  virtual void BuildPhone(void) = 0;
  virtual void BuildTablet(void) = 0;
  virtual void BuildScreen(void) = 0;
  virtual void BuildLaptop(void) = 0;
};
// -----------------------------------------------------------------------------

// Ha Noi shop
class HanoiShop final : public IShopBuilder {
 public:
  HanoiShop() { e_product_ = std::make_unique<ElectronicProduct>(); };
  HanoiShop(const HanoiShop&) = delete;
  HanoiShop& operator=(const HanoiShop&) = delete;
  ~HanoiShop() override = default;

  std::unique_ptr<ElectronicProduct> GetProduct() override {
    return std::move(e_product_);
  }

  void BuildPhone(void) override { e_product_->SetPhone("Galaxy s22 ultra"); }
  void BuildTablet(void) override { e_product_->SetTablet("Galaxy tab"); }
  void BuildScreen(void) override { e_product_->SetScreen("Toshiba LCD oled"); }
  void BuildLaptop(void) override { e_product_->SetLaptop("MSI"); }

 private:
  std::unique_ptr<ElectronicProduct> e_product_;
};

// HCM shop
class HcmShop final : public IShopBuilder {
 public:
  HcmShop() { e_product_ = std::make_unique<ElectronicProduct>(); };
  HcmShop(const HcmShop&) = delete;
  HcmShop& operator=(const HcmShop&) = delete;
  ~HcmShop() override = default;

  std::unique_ptr<ElectronicProduct> GetProduct() override {
    return std::move(e_product_);
  }

  void BuildPhone(void) override { e_product_->SetPhone("Iphone 14 pro max"); }
  void BuildTablet(void) override { e_product_->SetTablet("Ipad"); }
  void BuildScreen(void) override { e_product_->SetScreen("Samsung LCD"); }
  void BuildLaptop(void) override { e_product_->SetLaptop("Macbook Air"); }

 private:
  std::unique_ptr<ElectronicProduct> e_product_;
};
// -----------------------------------------------------------------------------

// Create Director build shop
class ContractorShop final {
 public:
  explicit ContractorShop(std::unique_ptr<IShopBuilder> shop_builder) {
    shop_builder_ = std::move(shop_builder);
  }
  ContractorShop(const ContractorShop&) = delete;
  ContractorShop& operator=(const ContractorShop&) = delete;
  ~ContractorShop() = default;

  std::unique_ptr<ElectronicProduct> GetProduct() {
    return std::move(shop_builder_->GetProduct());
  }

  void BuildProduct() {
    shop_builder_->BuildPhone();
    shop_builder_->BuildTablet();
    shop_builder_->BuildScreen();
    shop_builder_->BuildLaptop();
  }

 private:
  std::unique_ptr<IShopBuilder> shop_builder_;
};

int main() {
  std::unique_ptr<IShopBuilder> hanoi_shop = std::make_unique<HanoiShop>();
  std::unique_ptr<IShopBuilder> hcm_shop = std::make_unique<HcmShop>();

  std::unique_ptr<ContractorShop> hn_shop_ptr =
      std::make_unique<ContractorShop>(hanoi_shop);
  std::unique_ptr<ContractorShop> hcm_shop_ptr =
      std::make_unique<ContractorShop>(hcm_shop);

  hn_shop_ptr->BuildProduct();
  hn_shop_ptr->GetProduct()->ShowInfor();

  std::cout << "\n\n";

  hcm_shop_ptr->BuildProduct();
  hcm_shop_ptr->GetProduct()->ShowInfor();

  return 0;
}
