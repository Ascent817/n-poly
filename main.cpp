#include <iostream>
#include <tgmath.h>
#include <vector>

class Polynomial
{
public:
    std::vector<float> terms;

    Polynomial(std::vector<float> terms)
    {
        this->terms = terms;
    }

    int getOrder()
    {
        return terms.size() - 1;
    }

    float evaluate(float x)
    {
        float result = 0;
        for (int i = 0; i < terms.size(); i++)
        {
            int exponent = terms.size() - i - 1;
            result += terms[i] * pow(x, exponent);
        }
        return result;
    }

    Polynomial findDerivitive()
    {
        std::vector<float> derivitiveCoefficents;
        for (int i = 0; i < terms.size() - 1; i++)
        {
            int exponent = terms.size() - i - 1;
            derivitiveCoefficents.push_back(terms[i] * exponent);
        }

        for (int i = 0; i < derivitiveCoefficents.size(); i++)
        {
            std::cout << derivitiveCoefficents[i] << " ";
        }

        return Polynomial(derivitiveCoefficents);
    }

    std::vector<float> Solve(float prescision)
    {
        // First, solve the derivitive recursively
        if (getOrder() > 1)
        {
            Polynomial derivitive = findDerivitive();
            std::vector derivitiveZeros = derivitive.Solve(prescision);

            
        }
        else
        {
            // Solve the linear equation here
            return std::vector({-terms[1] / terms[0]});
        }
    }
};

int main()
{
    // Create the polynomial
    Polynomial original = Polynomial({1, 2, -2, -3, 1});

    return 0;
}