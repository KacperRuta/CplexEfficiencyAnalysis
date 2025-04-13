#include <ilcplex/ilocplex.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cmath>

ILOSTLBEGIN

int main() {
    try {
        IloEnv env;

        // Define garages and their data
        vector<string> garages = {
            "Winchester", "Andover", "Basingstoke", "Poole", "Woking", "Newbury",
            "Portsmouth", "Alresford", "Salisbury", "Guildford", "Alton", "Weybridge",
            "Dorchester", "Bridport", "Weymouth", "Portland", "Chichester", "Petersfield",
            "Petworth", "Midhurst", "Reading", "Southampton", "Bournemouth", "Henley",
            "Maidenhead", "Fareham", "Romsey", "Ringwood"
        };

        // Input data
        map<string, double> in_staff = {
            {"Winchester",7}, {"Andover",6}, {"Basingstoke",2}, {"Poole",14}, {"Woking",10},
            {"Newbury",24}, {"Portsmouth",6}, {"Alresford",8}, {"Salisbury",5}, {"Guildford",8},
            {"Alton",7}, {"Weybridge",5}, {"Dorchester",6}, {"Bridport",11}, {"Weymouth",4},
            {"Portland",3}, {"Chichester",5}, {"Petersfield",21}, {"Petworth",6}, {"Midhurst",3},
            {"Reading",30}, {"Southampton",25}, {"Bournemouth",19}, {"Henley",7}, {"Maidenhead",12},
            {"Fareham",4}, {"Romsey",2}, {"Ringwood",2}
        };

        map<string, double> in_space = {
            {"Winchester",8}, {"Andover",6}, {"Basingstoke",3}, {"Poole",9}, {"Woking",9},
            {"Newbury",15}, {"Portsmouth",7}, {"Alresford",7.5}, {"Salisbury",5}, {"Guildford",10},
            {"Alton",8}, {"Weybridge",6.5}, {"Dorchester",7.5}, {"Bridport",8}, {"Weymouth",5},
            {"Portland",3.5}, {"Chichester",5.5}, {"Petersfield",12}, {"Petworth",5.5}, {"Midhurst",3.6},
            {"Reading",29}, {"Southampton",16}, {"Bournemouth",10}, {"Henley",6}, {"Maidenhead",8},
            {"Fareham",6}, {"Romsey",2.5}, {"Ringwood",3.5}
        };

        map<string, double> in_pop1 = {
            {"Winchester",10}, {"Andover",20}, {"Basingstoke",40}, {"Poole",20}, {"Woking",10},
            {"Newbury",15}, {"Portsmouth",50}, {"Alresford",5}, {"Salisbury",10}, {"Guildford",30},
            {"Alton",7}, {"Weybridge",9}, {"Dorchester",10}, {"Bridport",8}, {"Weymouth",10},
            {"Portland",3}, {"Chichester",8}, {"Petersfield",6}, {"Petworth",2}, {"Midhurst",3},
            {"Reading",120}, {"Southampton",110}, {"Bournemouth",90}, {"Henley",5}, {"Maidenhead",7},
            {"Fareham",1}, {"Romsey",1}, {"Ringwood",2}
        };

        map<string, double> in_pop2 = {
            {"Winchester",12}, {"Andover",30}, {"Basingstoke",40}, {"Poole",25}, {"Woking",10},
            {"Newbury",13}, {"Portsmouth",40}, {"Alresford",8}, {"Salisbury",10}, {"Guildford",35},
            {"Alton",8}, {"Weybridge",12}, {"Dorchester",10}, {"Bridport",10}, {"Weymouth",10},
            {"Portland",20}, {"Chichester",10}, {"Petersfield",6}, {"Petworth",2}, {"Midhurst",3},
            {"Reading",80}, {"Southampton",80}, {"Bournemouth",22}, {"Henley",7}, {"Maidenhead",10},
            {"Fareham",1}, {"Romsey",1}, {"Ringwood",2}
        };

        map<string, double> in_alpha = {
            {"Winchester",8.5}, {"Andover",9}, {"Basingstoke",2}, {"Poole",10}, {"Woking",11},
            {"Newbury",25}, {"Portsmouth",8.5}, {"Alresford",9}, {"Salisbury",5}, {"Guildford",9.5},
            {"Alton",3}, {"Weybridge",8}, {"Dorchester",7.5}, {"Bridport",10}, {"Weymouth",7.5},
            {"Portland",2}, {"Chichester",7}, {"Petersfield",15}, {"Petworth",8}, {"Midhurst",2.5},
            {"Reading",35}, {"Southampton",27}, {"Bournemouth",25}, {"Henley",8.5}, {"Maidenhead",12},
            {"Fareham",7.5}, {"Romsey",2.5}, {"Ringwood",1.9}
        };

        map<string, double> in_beta = {
            {"Winchester",4}, {"Andover",4.5}, {"Basingstoke",1.5}, {"Poole",6}, {"Woking",5},
            {"Newbury",1.9}, {"Portsmouth",3}, {"Alresford",4}, {"Salisbury",2.5}, {"Guildford",4.5},
            {"Alton",2}, {"Weybridge",4.5}, {"Dorchester",4}, {"Bridport",6}, {"Weymouth",3.5},
            {"Portland",1.5}, {"Chichester",3.5}, {"Petersfield",8}, {"Petworth",5}, {"Midhurst",1.5},
            {"Reading",20}, {"Southampton",12}, {"Bournemouth",13}, {"Henley",4.5}, {"Maidenhead",7},
            {"Fareham",3.5}, {"Romsey",1}, {"Ringwood",1.2}
        };

        map<string, double> out_alpha = {
            {"Winchester",2}, {"Andover",2.3}, {"Basingstoke",0.8}, {"Poole",2.6}, {"Woking",2.4},
            {"Newbury",8}, {"Portsmouth",2.5}, {"Alresford",2.1}, {"Salisbury",2}, {"Guildford",2.05},
            {"Alton",1.9}, {"Weybridge",1.8}, {"Dorchester",1.5}, {"Bridport",2.2}, {"Weymouth",1.8},
            {"Portland",0.9}, {"Chichester",1.2}, {"Petersfield",6}, {"Petworth",1.5}, {"Midhurst",0.8},
            {"Reading",7}, {"Southampton",6.5}, {"Bournemouth",5.5}, {"Henley",1.2}, {"Maidenhead",4.5},
            {"Fareham",1.1}, {"Romsey",0.4}, {"Ringwood",0.3}
        };

        map<string, double> out_beta = {
            {"Winchester",0.6}, {"Andover",0.7}, {"Basingstoke",0.25}, {"Poole",0.86}, {"Woking",1},
            {"Newbury",2.6}, {"Portsmouth",0.9}, {"Alresford",0.85}, {"Salisbury",0.65}, {"Guildford",0.75},
            {"Alton",0.7}, {"Weybridge",0.63}, {"Dorchester",0.45}, {"Bridport",0.65}, {"Weymouth",0.62},
            {"Portland",0.35}, {"Chichester",0.45}, {"Petersfield",0.25}, {"Petworth",0.55}, {"Midhurst",0.2},
            {"Reading",2.5}, {"Southampton",3.5}, {"Bournemouth",3.1}, {"Henley",0.48}, {"Maidenhead",2},
            {"Fareham",0.48}, {"Romsey",0.1}, {"Ringwood",0.09}
        };

        map<string, double> out_prof = {
            {"Winchester",1.5}, {"Andover",1.6}, {"Basingstoke",0.5}, {"Poole",1.9}, {"Woking",2},
            {"Newbury",4.5}, {"Portsmouth",1.6}, {"Alresford",2}, {"Salisbury",0.9}, {"Guildford",1.7},
            {"Alton",0.5}, {"Weybridge",1.4}, {"Dorchester",1.45}, {"Bridport",2.2}, {"Weymouth",1.6},
            {"Portland",0.5}, {"Chichester",1.3}, {"Petersfield",2.9}, {"Petworth",1.55}, {"Midhurst",0.45},
            {"Reading",8}, {"Southampton",5.4}, {"Bournemouth",4.5}, {"Henley",2}, {"Maidenhead",2.3},
            {"Fareham",1.7}, {"Romsey",0.55}, {"Ringwood",0.4}
        };

        map<string, double> efficiency;

        for (const string& k : garages) {
            IloModel dea_model(env);

            IloNumVarArray x(env, garages.size(), 0, IloInfinity);
            IloNumVar w(env, 0, IloInfinity);

            dea_model.add(IloMaximize(env, w));

            IloExpr staff_expr(env);
            IloExpr space_expr(env);
            IloExpr pop1_expr(env);
            IloExpr pop2_expr(env);
            IloExpr alpha_in_expr(env);
            IloExpr beta_in_expr(env);

            IloExpr alpha_out_expr(env);
            IloExpr beta_out_expr(env);
            IloExpr prof_out_expr(env);

            for (int j = 0; j < garages.size(); j++) {
                const string& garage_j = garages[j];

                staff_expr += in_staff[garage_j] * x[j];
                space_expr += in_space[garage_j] * x[j];
                pop1_expr += in_pop1[garage_j] * x[j];
                pop2_expr += in_pop2[garage_j] * x[j];
                alpha_in_expr += in_alpha[garage_j] * x[j];
                beta_in_expr += in_beta[garage_j] * x[j];

                alpha_out_expr += out_alpha[garage_j] * x[j];
                beta_out_expr += out_beta[garage_j] * x[j];
                prof_out_expr += out_prof[garage_j] * x[j];
            }

            dea_model.add(staff_expr <= in_staff[k]);
            dea_model.add(space_expr <= in_space[k]);
            dea_model.add(pop1_expr <= in_pop1[k]);
            dea_model.add(pop2_expr <= in_pop2[k]);
            dea_model.add(alpha_in_expr <= in_alpha[k]);
            dea_model.add(beta_in_expr <= in_beta[k]);

            dea_model.add(alpha_out_expr >= out_alpha[k] * w);
            dea_model.add(beta_out_expr >= out_beta[k] * w);
            dea_model.add(prof_out_expr >= out_prof[k] * w);

            staff_expr.end();
            space_expr.end();
            pop1_expr.end();
            pop2_expr.end();
            alpha_in_expr.end();
            beta_in_expr.end();
            alpha_out_expr.end();
            beta_out_expr.end();
            prof_out_expr.end();

            IloCplex cplex(dea_model);
            cplex.setOut(env.getNullStream());
            cplex.setWarning(env.getNullStream());

            if (!cplex.solve()) {
                env.error() << "Failed to optimize DEA model for garage " << k << endl;
                throw(-1);
            }

            efficiency[k] = cplex.getObjValue();

            cout << k << " Efficiency = " << (1.0 / cplex.getObjValue()) << endl;

            cplex.end();
            dea_model.end();
        }

        cout << "\nInefficient Garages:" << endl;
        for (const string& k : garages) {
            if (efficiency[k] > 1.0000001) {
                cout << "\t" << k << " (Efficiency: " << (1.0 / efficiency[k]) << ")" << endl;
            }
        }

        env.end();
    }
    catch (IloException& e) {
        cerr << "Concert exception caught: " << e << endl;
    }
    catch (...) {
        cerr << "Unknown exception caught" << endl;
    }

    return 0;
}