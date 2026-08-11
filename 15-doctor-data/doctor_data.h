// ERROR: FILE CORRUPTED. Please supply valid C++ Code.

// hp1, üapöhp2ö % Äcountöiöma1,
//     öhp2ö % Älawöhp3öö / önextöstepö % Ädacöiöml1ö % Älawö7ö % Ädacöiömb1ö %
//         Ärandomöö % Äscrö9sö % Äsirö9sö % Äxctöhr1ö % Äaddöiömx1ö %
//         Ädacöiömx1ö % Äswapö % Äaddöiömy1ö % Ädacöiömy1ö % Ärandomö % Äscrö9sö %
//         Äsirö9sö % Äxctöhr2ö % Ädacöiömdyö % Ädioöiömdxö % Äsetupö.hpt,
//     3ö % Älacöranö % Ädacöiömth

#pragma once
#include <string>

namespace star_map {
    enum class System{
        AlphaCentauri,
        BetaHydri,
        DeltaEridani,
        EpsilonEridani,
        Omicron2Eridani,
        Sol
    };
}

namespace heaven {
    class Vessel {
        public:
            std::string name;
            int generation;
            int busters{0};
            star_map::System current_system{star_map::System::Sol};

            Vessel(std::string name, int gen);
            Vessel(std::string name, int gen, star_map::System system);
            heaven::Vessel replicate(std::string name);
            void make_buster();
            bool shoot_buster();           
    };
    std::string get_older_bob(heaven::Vessel subject1, heaven::Vessel subject2);
    bool in_the_same_system(heaven::Vessel subject1, heaven::Vessel subject2);
}