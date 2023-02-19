import tkinter as tk
import random


class SortVisualizer:
    def __init__(self):
        self.root = tk.Tk()
        self.root.title("Sorting Visualizer")
        self.width = 1000
        self.height = 800
        self.num_elements = 25
        self.sorting = False
        self.pivot_element = None
        self.current_element = None
        self.lowest_element = None
        self.sorted_element = None
        self.delay_time = 50
        self.array = self.generate_array(self.num_elements)
        self.sort_options = ["Bubble Sort", "Selection Sort", "Insertion Sort"]
        self.sort_algorithm = tk.StringVar(value="Bubble Sort")
        self.setup_gui()
        self.root.mainloop()

    def generate_array(self, num_elements) -> list:
        return [random.randint(10, 790) for _ in range(num_elements)]

    def draw_array(self, array) -> None:
        self.canvas.delete("all")
        width = self.width / (len(array) + 1)
        for i, value in enumerate(array):
            x1, y1 = i * width, self.height - value
            x2, y2 = (i + 1) * width, self.height
            color = "blue"
            if i == self.pivot_element:
                color = "#00FF00"
            elif i == self.current_element:
                color = "#FF0000"
            elif i == self.lowest_element:
                color = "#FF8C00"
            self.canvas.create_rectangle(x1, y1, x2, y2, fill=color)
        self.root.update()

    def bubble_sort(self) -> None:
        n = len(self.array)
        for i in range(n):
            made_swap = False
            for j in range(n - i - 1):
                if self.array[j] > self.array[j + 1]:
                    self.pivot_element = j
                    self.current_element = j + 1
                    self.draw_array(self.array)
                    self.root.update()
                    self.root.after(self.delay_time)
                    self.array[j], self.array[j +
                                              1] = self.array[j + 1], self.array[j]
                    made_swap = True
                    self.draw_array(self.array)
                    self.root.update()
                    self.root.after(self.delay_time)
                    self.pivot_element = None
            self.current_element = None
            self.sorted_element = n - i - 1
            self.draw_array(self.array)
            self.root.update()
            self.root.after(self.delay_time)
            # If no swaps were made during this pass, the array is sorted and we can exit early
            if not made_swap:
                break

    def selection_sort(self) -> None:
        n = len(self.array)
        for i in range(n):
            self.pivot_element = self.lowest_element = i
            min_index = i
            for j in range(i + 1, n):
                self.current_element = j
                self.draw_array(self.array)
                self.root.update()
                self.root.after(self.delay_time)
                if self.array[j] < self.array[min_index]:
                    self.lowest_element = j
                    self.draw_array(self.array)
                    self.root.update()
                    self.root.after(self.delay_time)
                    min_index = j
            if min_index != i:
                self.array[i], self.array[min_index] = (
                    self.array[min_index],
                    self.array[i],
                )
            self.pivot_element = None
            self.lowest_element = None
            self.current_element = None
            self.draw_array(self.array)
            self.root.update()
            self.root.after(self.delay_time)

    def insertion_sort(self) -> None:
        n = len(self.array)
        for i in range(1, n):
            j = self.pivot_element = self.current_element = i
            while j > 0 and self.array[j - 1] > self.array[j]:
                self.current_element = j
                self.lowest_element = j - 1
                self.draw_array(self.array)
                self.root.update()
                self.root.after(self.delay_time)
                self.array[j - 1], self.array[j] = self.array[j], self.array[j - 1]
                j -= 1
            self.pivot_element = None
            self.current_element = None
            self.lowest_element = None
            self.draw_array(self.array)
            self.root.update()
            self.root.after(self.delay_time)

    def final_sort(self) -> None:
        self.delay_time = 30
        for i in range(len(self.array)):
            self.pivot_element = i
            self.draw_array(self.array)
            self.root.update()
            self.root.after(self.delay_time)
        self.pivot_element = None
        self.draw_array(self.array)
        self.root.update()
        self.root.after(self.delay_time)
        self.sorting = True

    def run_sorting(self) -> None:
        # disable slider and other button while sorting
        self.slider.config(state=tk.DISABLED)
        self.sort_button.config(state=tk.DISABLED)
        self.dropdown.config(state=tk.DISABLED)

        sorting_algorithms = {
            "Bubble Sort": self.bubble_sort,
            "Selection Sort": self.selection_sort,
            "Insertion Sort": self.insertion_sort,
        }
        sort_function = sorting_algorithms.get(self.sort_algorithm.get())
        if sort_function:
            sort_function()
            self.final_sort()
        self.sorting = False

        # enable slider and other button after sorting
        self.slider.config(state=tk.NORMAL)
        self.sort_button.config(state=tk.NORMAL)
        self.dropdown.config(state=tk.NORMAL)

    def handle_sort_button(self) -> None:
        if not self.sorting:
            self.sorting = True
            self.run_sorting()

    def setup_gui(self) -> None:
        self.canvas = tk.Canvas(
            self.root, width=self.width, height=self.height, bg="white"
        )
        self.canvas.grid(row=1, column=0, columnspan=4)

        self.slider = tk.Scale(
            self.root,
            from_=3,
            to=500,
            resolution=1,
            orient=tk.HORIZONTAL,
            label="Number of elements",
            command=self.handle_slider,
            length=500,
        )
        self.slider.set(self.num_elements)
        self.slider.config(bg="#EAA222", fg="black",
                           highlightbackground="black")
        self.slider.grid(row=0, column=0)

        self.delay_slider = tk.Scale(
            self.root,
            from_=0,
            to=2.5,
            resolution=0.01,
            orient=tk.HORIZONTAL,
            label="Delay (s)",
            command=self.handle_delay_slider,
            length=300,
        )
        self.delay_slider.set(self.delay_time / 1000)
        self.delay_slider.config(
            bg="#EAA222", fg="black", highlightbackground="black")
        self.delay_slider.grid(row=0, column=1)

        self.dropdown = tk.OptionMenu(
            self.root, self.sort_algorithm, *self.sort_options
        )
        self.dropdown.config(bg="yellow", fg="black",
                             highlightbackground="black")

        self.dropdown.grid(row=0, column=2)

        self.sort_button = tk.Button(
            self.root, text="Sort", command=self.handle_sort_button
        )
        self.sort_button.config(bg="#00FF00", fg="black",
                                highlightbackground="black")
        self.sort_button.grid(row=0, column=3)

        self.draw_array(self.array)

    def handle_slider(self, value) -> None:
        self.num_elements = int(value)
        if self.num_elements != len(self.array):
            self.array = self.generate_array(self.num_elements)
            self.draw_array(self.array)

    def handle_delay_slider(self, value) -> None:
        self.delay_time = int(float(value) * 1000)
