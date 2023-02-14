import time
import multiprocessing

class SortAlgoComparator:
    def __init__(self):
        self.__data = []

    def read_data(self, filename):
        with open(filename, "r") as file:
            self.__data = [int(elem) for line in file for elem in line.strip().split()]
            return len(self.__data)

    def sort(self, algo, algo_name, timeout=10):
        process = multiprocessing.Process(target=algo, name=algo_name, args=(self.__data,))
        
        print(algo_name, "started...")
        start_time = time.time()
        process.start()
        end_time = time.time()

        process.join(timeout)       # set timeout

        if process.is_alive():
            print(algo_name, "timed out")
            process.terminate()
            process.join()
        else:
            print("%s: %.3f seconds" % (algo_name, end_time - start_time))