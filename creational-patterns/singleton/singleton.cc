/*
 * C++ Design Patterns: Singleton
 * Author: AnNT
 * 2023
 */

#include <iostream>
#include <memory>
#include <string_view>

class Database {
 public:
  Database(const Database &) = delete;
  Database &operator=(const Database &) = delete;
  ~Database() = default;

  static Database* GetInstance(std::string_view name) {
    if (nullptr == instance_ptr_) {
      // Since the unique_ptr class is not a member of the Database class,
      // it is not possible to call the Database constructor in private
      // Here is a way to make unique_ptr callable to Database constructor
      instance_ptr_ = std::unique_ptr<Database>(new Database(name));
    }
    // Cannot use std::move unique_ptr because it will assign instance_ptr_ = null_ptr
    return instance_ptr_.get();
  }

  // The second way is to let the std::make_shared constructor be a friend of
  // the Database class so that you can call the private property of the Database.
  // friend std::unique_ptr<Database> std::make_unique<Database>(std::string&);

  std::string_view GetName() const { return name_; }

 private:
  static std::unique_ptr<Database> instance_ptr_;
  std::string_view name_;

  explicit Database(std::string_view name) : name_{name} {}
};

// Static variables must be initialized outside the class area
std::unique_ptr<Database> Database::instance_ptr_{nullptr};

int main() {
  const auto database1 = Database::GetInstance("Products");
  std::cout << "This is the " << database1->GetName() << " database."
            << std::endl;

  const auto database2 = Database::GetInstance("Test");
  std::cout << "This is the " << database2->GetName() << " database."
            << std::endl;
  return 0;
}

/*
Output:
This is the Products database.
This is the Products database.
*/
