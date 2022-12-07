import { FaCode, FaPenAlt, FaUser } from 'react-icons/fa';
import { BsFillGearFill } from 'react-icons/bs';
import { useState } from 'react';

export default function Sidebar() {
  const [navBtns, setNavBtns] = useState({
    codeBtn: false,
    postBtn: false,
    editBtn: false,
    profileBtn: false,
  });

  function displayHoverCard(iconName) {
    console.log(navBtns[iconName]);
    setNavBtns({ ...navBtns, [iconName]: !navBtns[iconName] });
  }

  return (
    <div className="fixed top-0 left-0 h-screen w-[70px] text-white bg-primary-color ">
      <div className="flex flex-col m-4 h-screen justify-between">
        <div>
          <FaCode
            className="text-4xl mt-5 mb-12 hover:text-pink-300"
            onMouseEnter={() => displayHoverCard('codeBtn')}
            onMouseLeave={() => displayHoverCard('codeBtn')}
          />
          {navBtns.codeBtn && (
            <span className="fixed top-[35px] left-[75px] bg-secondary-color p-2 rounded">
              Codes
            </span>
          )}

          <FaPenAlt
            className="text-4xl mt-5 mb-12 hover:text-pink-300"
            onMouseEnter={() => displayHoverCard('postBtn')}
            onMouseLeave={() => displayHoverCard('postBtn')}
          />
          {navBtns.postBtn && (
            <span className="fixed top-[120px] left-[75px] bg-secondary-color p-2 rounded">
              Post Code
            </span>
          )}

          <BsFillGearFill
            className="text-4xl mt-5 mb-5 hover:text-pink-300"
            onMouseEnter={() => displayHoverCard('editBtn')}
            onMouseLeave={() => displayHoverCard('editBtn')}
          />
          {navBtns.editBtn && (
            <span className="fixed top-[203px] left-[75px] bg-secondary-color p-2 rounded">
              Edit Code
            </span>
          )}
        </div>

        <FaUser
          className="text-4xl mt-5 mb-10 hover:text-pink-300"
          onMouseEnter={() => displayHoverCard('profileBtn')}
          onMouseLeave={() => displayHoverCard('profileBtn')}
        />
      </div>
    </div>
  );
}
