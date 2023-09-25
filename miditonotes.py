import mido
from collections import namedtuple

# Define a named tuple to represent a Note
Note = namedtuple('Note', ['note_name', 'length', 'timeBetweenNotes'])

# Function to map MIDI note numbers to note names
def midi_to_note_name(note_number):
    note_names = ['C', 'CS', 'D', 'DS', 'E', 'F', 'FS', 'G', 'GS', 'A', 'AS', 'B']
    octave = (note_number // 12) - 1
    note_name = note_names[note_number % 12] + str(octave)
    return note_name

def midi_to_notes(midi_file):
    notes = []
    
    mid = mido.MidiFile(midi_file)
    current_time = 0
    note_on_time = {}
    
    for msg in mid:
        current_time += msg.time
        
        if msg.type == 'note_on' and msg.velocity > 0:
            note_on_time[msg.note] = current_time
        elif msg.type == 'note_off' or (msg.type == 'note_on' and msg.velocity == 0):
            if msg.note in note_on_time:
                note_start_time = note_on_time[msg.note]
                note_length = current_time - note_start_time
                note_name = midi_to_note_name(msg.note)
                notes.append(Note(note_name=note_name, length=note_length, timeBetweenNotes=current_time))
                del note_on_time[msg.note]

    return notes

if __name__ == "__main__":
    midi_file = "C:\\Users\\ivarn\\Downloads\\Wii.mid"
    notes = midi_to_notes(midi_file)

    for note in notes:
        print(f"Note({note.note_name}, {note.length * 1000:.0f}, {note.timeBetweenNotes * 1000:.0f}),")
