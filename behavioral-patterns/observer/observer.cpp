/*
 * C++ Design Patterns: Observer
 * Author: AnNT
 * 2023
 */

#include <algorithm>
#include <iostream>
#include <memory>
#include <string_view>
#include <vector>

/* * * * * * * * * * * * * * * * * *
 * Subject <--- add ---  observer 1
 * Subject <--- add ---  observer 2
 *
 * Subject -- notify --> observer 1
 * Subject -- notify --> observer 2
 *
 * Subject <-- remove -- observer 1
 *
 * Subject               observer 1
 * Subject -- notify --> observer 2
 *
 * Subject: Database
 * Observer: Client, Developer, Boss
 * * * * * * * * * * * * * * * * * * */

// Declare IObserver
class IObserver;

/*============================ INTERFACE =====================================*/
// Create subject interface
class ISubject {
 public:
  virtual void AddObserver(IObserver* observer) = 0;
  virtual void RemoveObserver(IObserver* observer) = 0;

  virtual void Notify(void) = 0;

 protected:
  virtual ~ISubject() = default;
};

// Crete observer interface
class IObserver {
 public:
  virtual void Update(std::string_view operation, std::string_view record) = 0;

 protected:
  virtual ~IObserver() = default;
};

/*============================================================================*/

// ------------------------- Crete subjects class ------------------------------
class Database final : public ISubject {
 public:
  Database() = default;
  Database(const Database&) = delete;
  Database& operator=(const Database&) = delete;
  ~Database() override = default;

  // ISubject
  void AddObserver(IObserver* observer) override {
    observers_.push_back(observer);
  }

  void RemoveObserver(IObserver* observer) override {
    const auto result =
        std::find(observers_.begin(), observers_.end(), observer);

    if (result != observers_.end()) {
      observers_.erase(result, result + 1);
    }
  }

  void Notify(void) override {
    for (const auto& observer : observers_) {
      observer->Update(operation_, record_);
    }
  }

  void EditRecord(std::string_view operation, std::string_view record) {
    operation_ = operation;
    record_ = record;
    Notify();
  }

 private:
  std::vector<IObserver*> observers_;

  std::string_view operation_;
  std::string_view record_;
};

// ------------------------- Crete observer class ------------------------------
class Client final : public IObserver {
 public:
  Client() = default;
  Client(const Client&) = delete;
  Client& operator=(const Client&) = delete;
  ~Client() override = default;

  // IObserver
  void Update(std::string_view operation, std::string_view record) override {
    std::cout << "\nClient - operation: [" << operation << "] record: <"
              << record << ">";
  }
};

class Developer final : public IObserver {
 public:
  Developer() = default;
  Developer(const Developer&) = delete;
  Developer& operator=(const Developer&) = delete;
  ~Developer() override = default;

  // IObserver
  void Update(std::string_view operation, std::string_view record) override {
    std::cout << "\nDeveloper - operation: [" << operation << "] record: <"
              << record << ">";
  }
};

class Boss final : public IObserver {
 public:
  Boss() = default;
  Boss(const Boss&) = delete;
  Boss& operator=(const Boss&) = delete;
  ~Boss() override = default;

  // IObserver
  void Update(std::string_view operation, std::string_view record) override {
    std::cout << "\nBoss - operation: [" << operation << "] record: <" << record
              << ">";
  }
};

/*============================== TESTING =====================================*/

int main() {
  const auto database = std::make_unique<Database>();

  const auto client = std::make_unique<Client>();
  const auto dev = std::make_unique<Developer>();
  const auto boss = std::make_unique<Boss>();

  database->AddObserver(client.get());
  database->AddObserver(dev.get());
  database->AddObserver(boss.get());

  database->EditRecord("delete", "record-001");

  // remove client
  std::cout << "\n----------------------------";
  std::cout << "\n  --- Remove Client ---";
  database->RemoveObserver(client.get());
  database->EditRecord("modify", "record-007");

  return 0;
}
