import mido
from mido import MidiFile, MidiTrack

def merge_midi_tracks(input_file):
    # Load the MIDI file
    midi_file = MidiFile(input_file)

    # Create a new MIDI track for merging
    merged_track = MidiTrack()

    # Iterate through each track in the original MIDI file
    for i, track in enumerate(midi_file.tracks):
        print(f"Processing Track {i + 1}")

        # Iterate through each message in the track
        for msg in track:
            # Add the message to the merged track
            merged_track.append(msg)

    # Create a new MIDI file with the merged track
    merged_file = MidiFile()
    merged_file.tracks.append(merged_track)

    # Save the merged MIDI file
    output_file = input_file.replace(".mid", "_merged.mid")
    merged_file.save(output_file)

    print(f"Merged MIDI file saved as: {output_file}")

if __name__ == "__main__":
    # Get input file from the user
    input_file = input("Enter the path to the MIDI file: ")

    # Call the function to merge MIDI tracks
    merge_midi_tracks(input_file)
