from skbuild import setup

project_name = "mymodule"

setup(
    name=project_name,
    version="0.0",
    packages=[f"{project_name}"],
    package_dir={"": "python"},
    cmake_install_dir=f"python/{project_name}",
    cmake_minimum_required_version="3.13...3.21",
)
