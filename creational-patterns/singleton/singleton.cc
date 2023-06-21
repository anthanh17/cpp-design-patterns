/*
 * C++ Design Patterns: Singleton
 * Author: AnNT
 * 2023
 */

#include <string>
#include <iostream>

class Database {
public:
  Database(const Database&) = delete;
  Database& operator=(const Database&) = delete;
  ~Database() = default;

  static Database *GetInstance(std::string name) {
    if (nullptr == instance_ptr_) {
      instance_ptr_ = new Database(name);
    }
    return instance_ptr_;
  }

  std::string GetName() const {
    return name_;
  }
private:
  static Database *instance_ptr_;
  std::string name_;

  explicit Database(std::string name) : name_{name} {}
};

Database *Database::instance_ptr_ = nullptr;

int main() {
  Database *database1 = Database::GetInstance("Products");
  std::cout << "This is the " << database1->GetName() << " database." << std::endl;

  Database *database2 = Database::GetInstance("Test");
  std::cout << "This is the " << database2->GetName() << " database." << std::endl;
  return 0;
}


/*
Output:
This is the Products database.
This is the Products database.
*/
