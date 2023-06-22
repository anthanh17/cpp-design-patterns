/*
 * C++ Design Patterns: Factory Method
 * Author: AnNT
 * 2023
 */

/*
Cửa hàng bán thức ăn cho động vật bán 3 loại thức ăn:
    - thức ăn cho mèo, cho chó và cho chuột.

- Thức ăn cho mèo có vị ngọt và giá 5$
- Thức ăn cho chó có vị chua và giá 10$
- Thức ăn cho chuột có vị cay và giá 5$

Tạo 1 chương trình đầu vào là 1 danh sách các số trong tập (1, 2, 3), phân tách
nhau bởi dấu cách với:
    - 1 là yêu cầu mua thức ăn cho mèo,
    - 2 là cho chó
    - 3 là cho chuột.

In ra màn hình 2 dòng:
- Dòng 1 bao gồm vị của thức ăn theo thứ tự yêu cầu mua trong đầu vào.
- Dòng 2 in ra tổng tiền cần thanh toán.

Yêu cầu: sử dụng C++ OOP, C++ std và design pattern thích hợp.

Ví dụ:
Input:
1 1 2 3 1
Output:
ngot ngot chua cay ngot
30
*/

#include <iostream>
#include <memory>
#include <sstream>
#include <string>

// -------------------------------- INTERFACE ----------------------------------
class IAnimal {
 public:
  virtual ~IAnimal() = default;

  virtual std::string GetFood() const = 0;
  virtual std::size_t GetPrice() const = 0;
};
// -----------------------------------------------------------------------------

class Cat final : public IAnimal {
 public:
  Cat() = default;
  Cat(const Cat&) = delete;
  Cat& operator=(const Cat&) = delete;
  ~Cat() override = default;

  std::string GetFood() const override { return "ngot "; }

  std::size_t GetPrice() const override { return 5; }
};

class Dog final : public IAnimal {
 public:
  Dog() = default;
  Dog(const Dog&) = delete;
  Dog& operator=(const Dog&) = delete;
  ~Dog() override = default;

  std::string GetFood() const override { return "chua "; }

  std::size_t GetPrice() const override { return 10; }
};

class Mouse final : public IAnimal {
 public:
  Mouse() = default;
  Mouse(const Mouse&) = delete;
  Mouse& operator=(const Mouse&) = delete;
  ~Mouse() override = default;

  std::string GetFood() const override { return "cay "; }

  std::size_t GetPrice() const override { return 5; }
};

// ------------------------------ FACTORY --------------------------------------
enum class AnimalType { CAT = 1, DOG, MOUSE };

class AnimalFactory {
 public:
  static std::unique_ptr<IAnimal> CreateAnimal(AnimalType type) {
    switch (type) {
      case AnimalType::CAT: {
        return std::make_unique<Cat>();
        break;
      }

      case AnimalType::DOG: {
        return std::make_unique<Dog>();
        break;
      }

      case AnimalType::MOUSE: {
        return std::make_unique<Mouse>();
        break;
      }
    }
    return nullptr;
  }
};

int main() {
  std::string input;
  // read a full line of text into input
  std::getline(std::cin >> std::ws, input);
  std::stringstream iss(input);

  int number{0};
  std::size_t sum{0};

  while (iss >> number) {
    std::unique_ptr<IAnimal> animal =
        AnimalFactory::CreateAnimal(static_cast<AnimalType>(number));

    std::cout << animal->GetFood();
    sum += animal->GetPrice();
  }
  std::cout << "\n" << sum;

  return 0;
}
