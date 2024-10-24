import subprocess
import csv
import logging

def setup_logging(name: str):

    # Create a logger
    logger = logging.getLogger(name)
    logger.setLevel(logging.INFO)  # Set the minimum logging level

    # Ensure the logger only logs to our handlers (no duplicate logs)
    logger.propagate = False

    # Check if the logger already has handlers
    if not logger.handlers:
        # Create a console handler
        handler = logging.StreamHandler()

        # Define a formatter with the desired timestamp format
        #formatter = logging.Formatter('[%(asctime)s] [%(name)s] [%(levelname)s] %(message)s', datefmt='%m-%d %H:%M')
        # remove the [(levelnames)s] because we only use log.info so it's always [INFO]
        formatter = logging.Formatter('[%(asctime)s] [%(name)s] %(message)s', datefmt='%m-%d %H:%M')
        # Set the formatter for the handler
        handler.setFormatter(formatter)

        # Add the handler to the logger
        logger.addHandler(handler)

    return logger


class DisplayFilter(logging.Filter):
    """A custom filter which enables or disables logging based on a flag."""
    def __init__(self, display=True):
        super().__init__()
        self.display = display

    def filter(self, record):
        """Determines if the specified record is to be logged."""
        return self.display

def setup_logging_with_filter(name: str):
    logger = logging.getLogger(name)
    logger.setLevel(logging.INFO)  # Set the minimum logging level
    logger.propagate = False

    if not logger.handlers:
        handler = logging.StreamHandler()
        formatter = logging.Formatter('[%(asctime)s] [%(name)s] [%(levelname)s] %(message)s', datefmt='%m-%d %H:%M')
        handler.setFormatter(formatter)
        
        logger.addHandler(handler)

    # Add the display filter with default behavior
    display_filter = DisplayFilter()
    for handler in logger.handlers:
        handler.addFilter(display_filter)
    
    # Function to change display setting dynamically
    def set_display(display):
        display_filter.display = display

    # Attach the function to the logger object
    logger.set_display = set_display

    return logger

class CSVLog:
    """
    Class to organize output csv file
    """
    def __init__(self, filename):
        self.filename = filename
        self.file = None
        self.writer = None

    def log(self, fields):
        if self.file is None:
            self.file = open(self.filename, 'w', newline='')
            self.writer = csv.DictWriter(self.file, fieldnames=fields.keys())
            self.writer.writeheader()
        self.writer.writerow(fields)
        self.file.flush()

    def close(self):
        if self.file is not None:
            self.file.close()


def get_git_version(path):
    try:
        git_version = subprocess.check_output(['git', '-C', path, 'describe', '--always', '--long', '--tags', '--dirty'], stderr=subprocess.PIPE)
    except subprocess.CalledProcessError as e:
        if b"not a git repository" in e.stderr:
            log.warning("WARNING: Path is not in a git repository so version tracking is not available.", stacklevel=2)
        else:
            log.warning("WARNING: Error when attempting to check git version so version tracking is not available.", stacklevel=2)
        return None
    else:
        git_version = git_version.decode().strip()
        if "-dirty" in git_version:
            log.warning("WARNING: The git repository has uncommitted changes. Please commit changes before running "
                        "WatChMaL code for proper version control", stacklevel=2)
        return git_version
