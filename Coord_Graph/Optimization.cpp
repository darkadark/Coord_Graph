#include "pch.h"
#include "Optimization.h"


std::random_device rd;
std::mt19937 gen(rd());


std::vector<double> DetermineSearch::Optimize(const std::vector<double>& x_0, std::vector<std::vector<double>>& path) {
    std::vector<double> x = x_0;
    //path.push_back(x);
    int n = 0;
    while (!stop_crit.NeedStop(x, f(x), n)) {
        std::vector<double> x_prev = x;
        path.push_back(x_prev);
        for (int i = 0; i < x.size(); ++i) {
            auto f1 = [&x, i, this](double x_i)->double {
                x[i] = x_i;
                return f(x);
            };
            x[i] = onedim_opt->Optimize(r[i], l[i], f1);
        }
        
        ++n;

    }
    return x;
}

std::vector<double> RandomSearch::GenY(const std::vector<double>& x) {
    std::vector<double> y(dist.size());
    std::uniform_real_distribution<double> d(0, 1);
    double alpha = d(gen);
    if (alpha > p){
        for (int i = 0; i < dist.size(); ++i) {
            y[i] = dist[i](gen);
        }
    }
    else {
        for (int i = 0; i < dist.size(); ++i) {
            std::uniform_real_distribution<double> b(max(x[i] - delta, dist[i].a()), 
                min(x[i] + delta, dist[i].b()));
            y[i] = b(gen);
        }
    }
    return y;
}

std::vector<double> RandomSearch::Optimize(const std::vector<double>& x_0, std::vector<std::vector<double>>& path) {
    std::vector<double> x = x_0;
    path.push_back(x);
    int n = 0;
    while (!stop_crit.NeedStop(x, f(x), n)) {
        std::vector<double> y = GenY(x);
        if (f(x) > f(y))
            x.swap(y);
        path.push_back(x);
        ++n;
    }
    return x;
}

double TernarySearch::Optimize(double r, double l, std::function<double(double)> f) {
    double r0 = r;
    double l0 = l;
    while (r0 - l0 > eps) {
        double li = (2 * l0 + r0) / 3;
        double ri = (l0 + 2 * r0) / 3;
        if (f(li) < f(ri)) {
            r0 = ri;
        }
        else {
            l0 = li;
        }
    }
    return (r0 + l0) / 2;
}