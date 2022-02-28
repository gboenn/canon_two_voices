#include <iostream>
#include <random>
#include "Modul.h"

void make_cadence_0 (int last_pivot, vector<int>& notes, string& lead, string& second) {
    
    cout << lead << endl << second << endl;
    // in option 0 (I.) comes1 one is four steps below dux (5th)
    int comes1_pivot = last_pivot - 4;
    
    // do the cantizans cadence:
    vector<int> canti;
    int begin_cad = notes[last_pivot];
    cout << "begin_cad: " << begin_cad << endl;
    // up a step
    last_pivot += 1;
    int apu = notes[last_pivot];
//    if ((apu+1) % 12 == 0){
//        // if the downstep by a third lands on b then make it b flat
//        apu--;
//    }
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    // up a third
    last_pivot += 2;
    apu = notes[last_pivot];
    if ((apu+1) % 12 == 0) {
        // if the second note is a b make it b flat
        apu--;
    }
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    
    last_pivot -= 1;
    //down a half step
    apu--;
    //    if ((apu+1) % 12 == 0) {
    //        // if the second note is a b make it b flat
    //        apu--;
    //    }
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";

    // up half step to finalis
    last_pivot += 1;
    apu++;
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    int finalis = apu;
    for (auto it = canti.begin(); it != canti.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    // comes1 cadence:
    // comes 1 ends in an ocatve with dux and must do a major second up and down movt
    // ex. ending on b: b c# b
    // musica ficta problem
    
    comes1_pivot += 1;
    apu = notes[comes1_pivot];
    // if f or c then make it f# or c# if finalis is e or b
    if (((apu-5)%12==0&&(finalis-4)%12==0) || ((apu+1)%12==0&&(finalis+1)%12==0)) {
        apu++;
    }
    second += std::to_string(apu);
    second += ",";
    comes1_pivot -= 1;
    apu = notes[comes1_pivot];
    // if cadence ends on Bb then lower last note to Bb
    if ((apu+1)%12==0&&(finalis+2)%12==0)
        apu--;
    second += std::to_string(apu);
}

void make_cadence_1 (int last_pivot, vector<int>& notes, string& lead, string& second) {
    
    cout << lead << endl << second << endl;
    // in option 0 (I.) comes1 one is four steps above dux (5th)
    int comes1_pivot = last_pivot + 4;
    
    // do the cantizans cadence:
    vector<int> canti;
    int begin_cad = notes[last_pivot];
    cout << "begin_cad: " << begin_cad << endl;
    // down a step
    last_pivot -= 1;
    int apu = notes[last_pivot];
//    if ((apu+1) % 12 == 0){
//        // if the downstep by a third lands on b then make it b flat
//        apu--;
//    }
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    // up a fourth
    last_pivot += 3;
    apu = notes[last_pivot];
    if ((apu+1) % 12 == 0) {
        // if the second note is a b make it b flat
        apu--;
    }
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    
    last_pivot -= 1;
    //down a half step
    apu--;
    //    if ((apu+1) % 12 == 0) {
    //        // if the second note is a b make it b flat
    //        apu--;
    //    }
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";

    // up half step to finalis
    last_pivot += 1;
    apu++;
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    int finalis = apu;
    for (auto it = canti.begin(); it != canti.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    // comes1 cadence:
    // comes 1 ends in an ocatve with dux and must do a major second up and down movt
    // ex. ending on b: b c# b
    // musica ficta problem
    
    comes1_pivot -= 1;
    apu = notes[comes1_pivot];
    // if f or c then make it f# or c# if finalis is e or b
    if (((apu-5)%12==0&&(finalis-4)%12==0) || ((apu+1)%12==0&&(finalis+1)%12==0)) {
        apu++;
    }
    second += std::to_string(apu);
    second += ",";
    comes1_pivot -= 1;
    apu = notes[comes1_pivot];
    // if cadence ends on Bb then lower last note to Bb
    if ((apu+1)%12==0&&(finalis+2)%12==0)
        apu--;
    second += std::to_string(apu);
}


int main (int argc, char *argv[]) {

    string a = "";
    for(int ndx{}; ndx != argc; ++ndx) {
        a = argv[ndx];
    }

    int option = stoi(a); //0;
    if (option < 0 && option > 1) {
        cout << "Usage: sketch <0 or 1>" << endl;
        return 0;
    }
    
    // option 0 : at the fifth below c - f
    // option > 0 : at the fifth above f - c
    
    // loading the chunking library by creating an instance of its class 'Modul'
    Modul m;
    
    // create a random generator
    random_device rd;
    mt19937 md(rd());
    
    // creating the gamut
    vector<int> scale = {2,2,1,2,2,2,1};
    // all available notes are stored in this vector:
    vector<int> notes;
    // four octaves starting with C3
    int note = 48;
    notes.push_back (note);
    for (auto i = 0; i < 4; i++) {
        for (auto it = scale.begin(); it != scale.end(); ++it) {
            note += *it;
            notes.push_back (note);
        }
    }
    
    for (auto it = notes.begin(); it != notes.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // the steps of the scale that are allowed for the canon at the fifth below
    // note the intervals are not given in the number of semitones but in steps
    // 0 := unison, 1 := major/minor second, 2: major/minor third, etcetera
    // a minus sign changes the direction of the step to a downwards interval
    vector<int> intervals_5b = {3,1,0,-2,-4};
    if (option == 1) {
        cout << "fifth above" << endl;
        // for the canon at the fifth above allows these steps
        intervals_5b = {2,4,0,-3,-1};
    }
    // create a random distribution
    uniform_real_distribution<double> dist_up(0, intervals_5b.size());
    
    // start the leader on C5 for the canon at the fifth below
    int pivot = 14;
    if (option == 1) {
        // for the canon at the fifth above, start the leader on F4
        pivot = 10;
    }
    vector<int> dux; // save the leader's notes (dux) in a vector
    unsigned long num_notes = 12; // the number of notes - this could be given by the command line
    dux.push_back(notes[pivot]);
    // keep track of the previous and the current note, as well as the current and previous intervals
    int prev_note = notes[pivot];
    int curr_note = notes[pivot];
    int prev_intv = 0;
    int curr_intv = 0;
    while (dux.size() < num_notes) {
        unsigned long r = static_cast<unsigned long>(dist_up(md));
        curr_intv = intervals_5b[r];
        int check = abs(curr_intv + prev_intv);
        // avoid a big interval after a small one in the same direction
        // avoid more than one note repitition
        int check2 = abs(curr_intv) + abs(prev_intv);
//        avoid jumping fourth and fifth
        if (check < 4 && check != 0 && check2 != 7) {
            if (pivot + curr_intv < 0) {
            //                curr_intv = prev_intv;
                continue;
            }
            if (static_cast<unsigned int>(pivot + curr_intv) >= notes.size()) {
//                curr_intv = prev_intv;
                continue;
            }
            
            pivot += curr_intv;
            curr_note = notes[pivot];
            // no tritone jump
            if (abs(curr_note - prev_note) != 6
                && abs(curr_note - prev_note) < 9) {
//                cout << (abs(curr_note - prev_note) < 9) <<
//                " " << abs(curr_note - prev_note) << endl;
                dux.push_back(notes[pivot]);
                prev_note = curr_note;
                prev_intv = curr_intv;
            } else {
                //reset pivot
                pivot -= curr_intv;
            }
        }
    }
    
    string midiline = "";
    ofstream rhy("rhythm.txt");
    ofstream output("mel.txt");
    for (auto it = dux.begin(); it != dux.end(); ++it) {
        midiline += std::to_string(*it) + ", ";
    }
        
    string comes = "";
    if (option == 0) {
        comes = m.Transpose2(midiline, -7.);
        make_cadence_0 (pivot, notes, midiline, comes);
    }
    if (option == 1) {
        comes = m.Transpose2(midiline, 7.);
        make_cadence_1 (pivot, notes, midiline, comes);
    }
    
    output  << midiline << endl;
    cout << "dux: " << midiline << endl;
    for (auto it = dux.begin(); it != dux.end(); ++it) {
        rhy << "W";
    }
    if (option == 0)
        rhy << "HWHW";
    else if (option == 1)
        rhy << "HWHW";
    rhy << endl;
    
    output << "S" << endl;
    output << comes << endl;
    rhy << "S" << endl << "(W)";
    for (auto it = dux.begin(); it != dux.end(); ++it) {
        rhy << "W";
    }
    if (option == 0)
        rhy << "WW";
    else if (option == 1)
        rhy << "WW";
    rhy << endl;
    
    output.close();
    rhy.close();
    m.Translate_Shorthand("rhythm.txt", "mel.txt", 8);
    system("lilypond.sh transcription.ly");
    system("preview.sh transcription.pdf");
    system("timidity -T 180 transcription.midi");
  return 0;
}

