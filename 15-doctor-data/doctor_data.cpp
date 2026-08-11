// ERROR: FILE CORRUPTED. Please supply valid C++ Code.

// hp4,ölacöiömthö%Äsmaö%Äsubö(311040ö%Äspaö%Äaddö(311040ö%Ädacöiömthö%Äcountö.hpt,hp4ö%Äxctöhd2ö%Ädacöiöma1
// hp2,öjmpö.

#include "doctor_data.h"

heaven::Vessel::Vessel(std::string name, int gen) {
    heaven::Vessel::name = name;
    heaven::Vessel::generation = gen;
    heaven::Vessel::current_system = star_map::System::Sol;
}

heaven::Vessel::Vessel(std::string name, int gen, star_map::System system) {
    heaven::Vessel::name = name;
    heaven::Vessel::generation = gen;
    heaven::Vessel::current_system = system;
}

heaven::Vessel heaven::Vessel::replicate(std::string name) {
    return heaven::Vessel {name, heaven::Vessel::generation + 1, heaven::Vessel::current_system};
}

void heaven::Vessel::make_buster() {
    heaven::Vessel::busters += 1;
}

bool heaven::Vessel::shoot_buster() {
    if (heaven::Vessel::busters > 0) {
        heaven::Vessel::busters -= 1;
        return true;
    }
    return false;
}

std::string heaven::get_older_bob(heaven::Vessel subject1, heaven::Vessel subject2) {
    if (subject1.generation < subject2.generation) {
        return subject1.name;
    }
    return subject2.name;
}

bool heaven::in_the_same_system(heaven::Vessel subject1, heaven::Vessel subject2) {
    if (subject1.current_system == subject2.current_system) {
        return true;
    }
    return false;
}
