#include <Arduino.h>
#include <list>
#include "Itertools.hpp"

void setup() {
    namespace sc = softcast;
    Serial.begin(115200);
    Serial.println("\n");

    auto names = {
        "Adam",
        "Jane",
        "Ivan",
        "Klaus",
        "Sarah",
        "Siergiej",
        "Mike",
        "Jurgen",
        "Nataly"
    };

    std::vector<const char*> german_names = {
        "Klaus",
        "Jurgen"
    };

    std::list<const char*> employees = {
        "Nataly",
        "Ivan",
        "Sarah",
        "Thomas"
    };

    std::array<uint8_t, 5>         lucky_numbers = {7, 9, 13, 21, 69};
    std::initializer_list<uint8_t> prime_numbers = {2, 3, 5, 7 , 11, 13};

    bool is_luckuy_prime = sc::match_elements(prime_numbers, lucky_numbers);
    Serial.printf("prime numbers contain lucky numbers = %d \n", is_luckuy_prime);

    bool is_all_german_inside = sc::match_elements(names, german_names);
    Serial.printf("all german names are in names list = %d \n", is_all_german_inside);

    bool is_all_employees_inside = sc::match_elements(names, employees);
    Serial.printf("all employees names are in names list = %d \n", is_all_employees_inside);

    Serial.printf("index of Sarah in employees list = %d \n", sc::index_of(employees, "Sarah"));

    auto names_contains = sc::contains(names, "Mike", "Adam");
    Serial.printf("names contain Mike and Adam = %d \n", names_contains);

    auto names_contains_oneof = sc::contains_oneof(names, "Jack", "Siergiej", "Lucy");
    Serial.printf("names contain one of Jack, Siergiej or Lucy = %d \n", names_contains_oneof);
}

void loop() {}