export default function SearchBar() {
  return (
    <div className="flex mx-40 my-4 justify-around ">
      <ul className="flex text-white">
        <li className="m-2 font-medium hover:text-red-400">all*</li>
        <li className="m-2 font-medium hover:text-red-400">sem2</li>
        <li className="m-2 font-medium hover:text-red-400">sem3</li>
        <li className="m-2 font-medium hover:text-red-400">sem4</li>
        <li className="m-2 font-medium hover:text-red-400">sem5</li>
        <li className="m-2 font-medium hover:text-red-400">sem6</li>
        <li className="m-2 font-medium hover:text-red-400">sem7</li>
        <li className="m-2 font-medium hover:text-red-400">sem8</li>
      </ul>
      <input
        class="w-60 placeholder:italic placeholder:text-slate-400 block bg-white w-full border border-slate-300 rounded-md py-2 pl-9 pr-3 shadow-sm focus:outline-none focus:border-sky-500 focus:ring-sky-500 focus:ring-1 sm:text-sm"
        placeholder="Search and find Programs"
        type="text"
        name="search"
      />
    </div>
  );
}
