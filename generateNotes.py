import mido
from mido import MidiFile

def midi_to_ms(ticks, ticks_per_beat, tempo):
    microseconds_per_beat = mido.bpm2tempo(tempo)
    microseconds_per_tick = microseconds_per_beat / ticks_per_beat
    ms_per_tick = microseconds_per_tick / 1000
    return int(ticks * ms_per_tick)

def note_number_to_name(note_number):
    notes = ['C', 'CS', 'D', 'DS', 'E', 'F', 'FS', 'G', 'GS', 'A', 'AS', 'B']
    octave = note_number // 12 - 1
    note_name = notes[note_number % 12]
    return f"{note_name}{octave}"

def print_notes(midi_file_path):
    midi_file = MidiFile(midi_file_path)

    for i, track in enumerate(midi_file.tracks):
        print(f"Track {i + 1}:")

        current_time = 0
        notes = {}

        for msg in track:
            current_time += msg.time

            if msg.type == 'note_on':
                note_name = note_number_to_name(msg.note)
                notes[msg.note] = {"start_time": current_time, "length": None}

            elif msg.type == 'note_off' and msg.note in notes:
                notes[msg.note]["length"] = current_time - notes[msg.note]["start_time"]
                time_until_next_note = msg.time

                print(f"{{Note{note_name}, {notes[msg.note]['length']}, {time_until_next_note}}},")

if __name__ == "__main__":
    # Get user input for the MIDI file path
    midi_file_path = input("Enter the path of the MIDI file: ")
    print_notes(midi_file_path)
