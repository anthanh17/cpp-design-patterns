/*
 * C++ Design Patterns: Singleton
 * Author: AnNT
 * 2023
 */

#include <iostream>
#include <memory>
#include <string>

class Database {
 public:
  Database(const Database &) = delete;
  Database &operator=(const Database &) = delete;
  ~Database() = default;

  static std::unique_ptr<Database> GetInstance(std::string name) {
    if (nullptr == instance_ptr_) {
      instance_ptr_ = std::make_unique<Database>(name);
      std::cout << "\nKhoi tao instance\n";
    }
    return std::move(instance_ptr_);
  }

  friend std::unique_ptr<Database> std::make_unique<Database>(std::string &);

  std::string GetName() const { return name_; }

 private:
  static std::unique_ptr<Database> instance_ptr_;
  std::string name_;

  explicit Database(std::string name) : name_{name} {}
};

std::unique_ptr<Database> Database::instance_ptr_{nullptr};

int main() {
  std::unique_ptr<Database> database1 = Database::GetInstance("Products");
  std::cout << "This is the " << database1->GetName() << " database."
            << std::endl;

  std::unique_ptr<Database> database2 = Database::GetInstance("Test");
  std::cout << "This is the " << database2->GetName() << " database."
            << std::endl;
  return 0;
}

/*
Output:
This is the Products database.
This is the Products database.
*/
