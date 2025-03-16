#include "customer.hpp"
#include <string>
#include <vector>

using vec_customers = std::vector<Customer>;

int
main()
{
    vec_customers customers;
    for (size_t i = 0; i < 8; i++)
    {
        customers.push_back("Customer " + std::to_string(i));
    }

    for (auto &customer : customers)
    {
        std::println("{}", customer.get_name());
    }

    for (auto &customer : customers)
    {
        std::println("{}", customer.get_name());
    }

    auto c1 = customers[0];

    for (auto &customer : customers)
    {
        std::println("{}", customer.get_name());
    }

    auto c2 = Customer{"Michael"};
    customers.push_back(c2);

    customers.push_back(Customer{"Andreas"});
}
